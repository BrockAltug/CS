from flask import Flask, render_template, request

app = Flask(__name__)

REGISTRANTS = {}
#SPORTS created so users can not create their own category from inspect element, for security
SPORTS = [
    "Basketball",
    "Soccer",
    "Football",
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    REGISTRANTS[name] = sport
    return render_template("success.html")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
