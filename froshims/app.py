from flask import Flask, render_template, request

app = Flask(__name__)
#cannot have variables same name as functions
REGISTRANTS = {} #dictionary to store values for name, sport, capital for global

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    REGISTRANTS[name] = sport
    return render_template("success.html")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)

