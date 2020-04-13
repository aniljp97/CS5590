
from flask import *
from detect import extract_feature
from detect import print_prediction
import os

PEOPLE_FOLDER = os.path.join('static', 'audio')
app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = PEOPLE_FOLDER


@app.route('/')
def upload():
    return render_template("file_upload_form.html")


@app.route('/success', methods=['POST'])
def success():
    if request.method == 'POST':
        f = request.files['file']
        det = extract_feature(f)
        # img.save(f.filename + "New")
        # f.save(f.filename)
        full_filename = os.path.join(app.config['UPLOAD_FOLDER'], "New_" + f.filename)
        return render_template("success.html", name=f.filename, audio=full_filename, detection=det)


if __name__ == '__main__':
    app.run(debug=True)
