import requests
from requests import session
import hashlib

payload = {
    'action': 'login',
    'username': 'youraccount',
    'password': 'yourpassword',
    'crsf' : '8d679201c7b4c7890d9bd268198ffe3a',
    'check' : 'true',
}

with session() as c:
    c.post('https://ringzer0team.com/login', data=payload)
    response = c.get('https://ringzer0team.com/challenges/13')
    res_text = (response.text)
    pos_start = res_text.find('MESSAGE')
    pos_end = res_text.find('END')
    message = str(res_text[pos_start+23:pos_end-16])
    message_hash = (hashlib.sha512(message).hexdigest())
    flag = c.get('https://ringzer0team.com/challenges/13/' + str(message_hash))
    print len(message)
    print message
    print message_hash
    print flag.text
