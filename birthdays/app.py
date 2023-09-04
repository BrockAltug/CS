# Import necessary modules
import os
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
import calendar  # Import the calendar module

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Create a function to get the month name from a numeric value
def get_month_name(month):
    if 1 <= month <= 12:
        return calendar.month_name[month]
    else:
        return "Invalid Month"

# Route for both GET and POST requests
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Get data from the form
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Insert the data into the database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)

    # Fetch all entries from the database or initialize as an empty list if there are no entries
    entries = db.execute("SELECT * FROM birthdays") or []

    return render_template("index.html", entries=entries, get_month_name=get_month_name)

# Route to handle removal of birthdays
@app.route("/remove/<int:id>", methods=["POST"])
def remove(id):
    # Remove the birthday with the specified ID from the database
    db.execute("DELETE FROM birthdays WHERE id = ?", id)

    # Redirect back to the main page
    return redirect("/")

if __name__ == "__main__":
    app.run()
