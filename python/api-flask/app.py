from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello_world():
    return "<p></p>"

# flask --app [filename] run

# return { "key": value } <- JSON