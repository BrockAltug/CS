from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///store.db")

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)

@app.route("/cart", methods=["GET", "POST"])
def cart():
    if "cart" not in session:
        session["cart"] = []

    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")

    book_ids = session["cart"]
    books = []
    total = 0
    if book_ids:
        books = db.execute("SELECT * FROM books WHERE id IN (?)", book_ids)
        total = sum(book["price"] for book in books)

    return render_template("cart.html", books=books, total=total)

@app.route("/remove", methods=["POST"])
def remove_from_cart():
    id = request.form.get("id")
    if id in session["cart"]:
        session["cart"].remove(id)
    return redirect("/cart")

if __name__ == "__main__":
    app.run(debug=True)
