import requests
from requests import session
import hashlib
import re
from datetime import datetime
payload = {
    'action': 'login',
    'username': 'account',
    'password': 'password',
    'crsf' : '8d679201c7b4c7890d9bd268198ffe3a',
    'check' : 'true',
}
def sha1_bruteforce(cmp_str, sand):
 for i in range(0, 10000):
  if(hashlib.sha1(str(i) + sand).hexdigest() == cmp_str):
   return str(i)

with session() as c:
    startTime = datetime.now()
    c.post('https://ringzer0team.com/login', data=payload)
    response = c.get('https://ringzer0team.com/challenges/57').text
    start_pos = response.find('HASH')+20
    hash = response[start_pos:start_pos+40]
    start_pos = response.find('SALT')+20
    sand = response[start_pos:start_pos+64]
    flag = c.get('https://ringzer0team.com/challenges/57/' + sha1_bruteforce(hash, sand)).text
    print datetime.now() - startTime
    
    f = open('flag.html', 'w')
    f.write(flag)
    f.close()

