from flask import Flask, render_template, request     #has 3 functions imported from Flask framework               #examples with GET / POST        and request.form for post

app = Flask(__name__)   #turns the file into a Flask application


@app.route("/", methods=["GET","POST"])
def index():
    #if "name" in request.args:
    #    name = request.args["names"]
    #else:
    #    name = "world"
    #name = request.args.get("name", "world")
    #return render_template("index.html", name=request.args.get("name", "world"))
    if request.method == "GET":
         return render_template("index.html") #, placeholder=name) #placeholder changed to name variable
    elif request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
