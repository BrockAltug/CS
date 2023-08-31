# Import necessary modules and functions from Flask
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Create a Flask web application instance
app = Flask(__name__)

# Configure session to use the filesystem and not be permanent
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Define a route for the root URL ("/")
@app.route("/")
def index():
    # Check if the "name" key exists in the session
    if not session.get("name"):
        # If not, redirect the user to the login page
        return redirect("/login")
    # If the "name" key exists, render the "index.html" template
    return render_template("index.html")

# Define a route for the "/login" URL, supporting GET and POST methods
@app.route("/login", methods=["GET", "POST"])
def login():
    # If the request method is POST (form submission)
    if request.method == "POST":
        # Store the submitted "name" value in the session
        session["name"] = request.form.get("name")
        # Redirect the user to the root URL ("/")
        return redirect("/")
    # If the request method is GET, render the "login.html" template
    return render_template("login.html")

# Define a route for the "/logout" URL
@app.route("/logout")
def logout():
    # Set the "name" value in the session to None (logging out)
    session["name"] = None
    # Redirect the user to the root URL ("/")
    return redirect("/")
