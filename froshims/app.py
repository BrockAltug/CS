from flask import Flask, render_template, request

app = Flask(__name__)

registrants = {}

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    return render_template("success.html")

