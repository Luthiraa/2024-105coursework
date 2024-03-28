import json
import random
from datetime import datetime

hr = random.randint(50,100)

current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

new_data = {
    'hr': hr,
    'time': current_time
}

# Read the existing data
try:
    with open('data.json', 'r') as f:
        data = json.load(f)
except (FileNotFoundError, json.JSONDecodeError):
    data = []

# Check if data is a list, if not, initialize it as a list
if not isinstance(data, list):
    data = []

data.append(new_data)

with open('data.json', 'a') as f:
    f.write(json_str + '\n')