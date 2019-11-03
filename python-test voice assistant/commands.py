//Program de teste pentru comenzile vocale. Versiunea finala a fost refacuta in javascript.
import requests
import json
from datetime import datetime
import socket
print (socket.gethostbyname(socket.gethostname()))

def getDateTime(requiredInfo):
    url = "http://worldtimeapi.org/api/ip/92.114.38.211.json"

    payload = "------WebKitFormBoundary7MA4YWxkTrZu0gW\r\nContent-Disposition: form-data; name=\"user\"\r\n\r\neugendanfodor@gmail.com\r\n------WebKitFormBoundary7MA4YWxkTrZu0gW\r\nContent-Disposition: form-data; name=\"password\"\r\n\r\neugen1234\r\n------WebKitFormBoundary7MA4YWxkTrZu0gW--"
    headers = {
    'content-type': "multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW",
    'cache-control': "no-cache",
    'Postman-Token': "de1b08d6-7d1b-4ef7-942e-efa30cac8f8a"
    }

    response = requests.request("GET", url, data=payload, headers=headers)

    response = str(response.text)

    response = json.loads(response)

    unix_timestamp = response['unixtime']

    timezone_utc_offset = response['utc_offset']

    timezone_utc_offset = timezone_utc_offset.replace("+", "")
    timezone_utc_offset = timezone_utc_offset.replace(":00", "")
    if timezone_utc_offset[0] == "0":
        timezone_utc_offset = timezone_utc_offset.replace("0", "")
        

    ts = int(unix_timestamp) + int(timezone_utc_offset)*3600

    full_date_time = datetime.utcfromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')

    year = datetime.utcfromtimestamp(ts).strftime('%Y')
    month = datetime.utcfromtimestamp(ts).strftime('%m')
    day = datetime.utcfromtimestamp(ts).strftime('%d')

    hour = datetime.utcfromtimestamp(ts).strftime('%H')
    if hour[0] == "0":
        hour = hour.replace("0", "")

    minute = datetime.utcfromtimestamp(ts).strftime('%M')
    second = datetime.utcfromtimestamp(ts).strftime('%S')

    if requiredInfo == "hour":
        returned_string = "Este ora " + hour + " și " + minute + " minute" 

    if requiredInfo == "date":
        returned_string = "astăzi suntem în data de " + day + " " + month + " " + year

    return returned_string
