import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Query database for user's portfolio
    rows = db.execute("SELECT symbol, SUM(shares) AS total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0", session["user_id"])

    # Initialize variables
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    portfolio = []
    total_value = cash

    # Populate portfolio with stock information
    for row in rows:
        stock = lookup(row["symbol"])
        total_shares = row["total_shares"]
        total_stock_value = stock["price"] * total_shares
        total_value += total_stock_value
        portfolio.append({"symbol": stock["symbol"], "name": stock["name"], "shares": total_shares, "price": usd(stock["price"]), "total": usd(total_stock_value)})

    return render_template("index.html", portfolio=portfolio, cash=usd(cash), total=usd(total_value))


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not symbol:
            return apology("must provide stock symbol")
        elif not shares:
            return apology("must provide number of shares")
        elif shares <= 0:
            return apology("number of shares must be positive")

        stock = lookup(symbol)

        if not stock:
            return apology("invalid stock symbol")

        # Calculate the cost of shares
        cost = stock["price"] * shares

        # Query user's cash balance
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        if cash < cost:
            return apology("not enough cash")

        # Update user's cash balance
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", cost, session["user_id"])

        # Record the transaction
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", session["user_id"], stock["symbol"], shares, stock["price"])

        flash("Stock purchased successfully!")
        return redirect(url_for("index"))

    else:
        return render_template("buy.html")

# Implement other routes for quote, sell, history, and registration here...

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("must provide stock symbol")

        stock = lookup(symbol)

        if not stock:
            return apology("invalid stock symbol")

        return render_template("quoted.html", quoted=stock)

    else:
        return render_template("quote.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not symbol:
            return apology("must select a stock to sell")
        elif shares <= 0:
            return apology("number of shares must be positive")

        stock = lookup(symbol)

        if not stock:
            return apology("invalid stock symbol")

        # Query user's shares of the selected stock
        user_shares = db.execute("SELECT SUM(shares) AS total_shares FROM transactions WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)[0]["total_shares"]

        if user_shares is None or user_shares < shares:
            return apology("not enough shares to sell")

        # Calculate the proceeds from the sale
        proceeds = stock["price"] * shares

        # Update user's cash balance
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", proceeds, session["user_id"])

        # Record the sale transaction
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", session["user_id"], stock["symbol"], -shares, stock["price"])

        flash("Stock sold successfully!")
        return redirect(url_for("index"))

    else:
        # Get the list of stocks owned by the user for the sell form
        stocks = db.execute("SELECT DISTINCT symbol FROM transactions WHERE user_id = ? AND shares > 0", session["user_id"])
        return render_template("sell.html", stocks=stocks)

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Query transaction history for the user
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = ? ORDER BY timestamp DESC", session["user_id"])

    return render_template("history.html", transactions=transactions)

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        # Get user input
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username and password are provided and match
        if not username:
            return apology("must provide username")
        elif not password:
            return apology("must provide password")
        elif password != confirmation:
            return apology("passwords do not match")

        # Hash the password
        hashed_password = generate_password_hash(password)

        # Insert the new user into the database
        result = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashed_password)

        if not result:
            return apology("username already exists")

        # Log in the new user
        user_id = db.execute("SELECT id FROM users WHERE username = ?", username)[0]["id"]
        session["user_id"] = user_id

        # Redirect to the portfolio page
        return redirect(url_for("index"))

    else:
        return render_template("register.html")


@app.route("/logout", methods=["GET"])
@login_required
def logout():
    # Clear the user session to log them out
    session.clear()
    # Redirect to the homepage
    return redirect("/")



if __name__ == "__main__":
    app.run()
