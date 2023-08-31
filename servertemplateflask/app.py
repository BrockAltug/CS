from flask import Flask, render_template, request

app = Flas(__name__)

@app.route("/")
def index():
    return render_template("index.html")

