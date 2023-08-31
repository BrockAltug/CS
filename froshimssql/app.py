#implements a registration form, storing registrants in a sqlite database

from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

db = SQL("sqlite://froshims.db")

