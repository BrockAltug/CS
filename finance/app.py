import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd

app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Disable caching for all routes
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # TODO: Implement this route to display the user's portfolio
    return render_template("index.html")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # TODO: Implement this route to allow users to buy shares
    if request.method == "POST":
        # Parse user input, validate, and execute the purchase
        # Insert a record into the transaction history table
        # Update user's cash balance and stock holdings
        # Redirect user to the home page
        return redirect("/")
    else:
        # Render the HTML form to buy stocks
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # TODO: Implement this route to display user's transaction history
    return render_template("history.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # TODO: Implement this route to handle user login
    if request.method == "POST":
        # Check user credentials, log them in, and redirect to the home page
        return redirect("/")
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out"""
    # TODO: Implement this route to log the user out
    session.clear()
    return redirect("/")

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # TODO: Implement this route to allow users to get stock quotes
    if request.method == "POST":
        # Parse user input, call lookup function, and render the quote
        return render_template("quoted.html", stock_info=stock_info)
    else:
        # Render the HTML form to get a stock quote
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # TODO: Implement this route to allow users to register
    if request.method == "POST":
        # Parse user input, validate, hash the password, and register the user
        return redirect("/login")
    else:
        # Render the HTML form to register a new user
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # TODO: Implement this route to allow users to sell shares
    if request.method == "POST":
        # Parse user input, validate, and execute the sale
        # Insert a record into the transaction history table
        # Update user's cash balance and stock holdings
        # Redirect user to the home page
        return redirect("/")
    else:
        # Render the HTML form to sell stocks
        return render_template("sell.html")

if __name__ == "__main__":
    app.run()
