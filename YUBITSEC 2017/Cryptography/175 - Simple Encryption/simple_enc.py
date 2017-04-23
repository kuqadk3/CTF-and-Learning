

f = open("encrypted","w")

secret = "***REDACTED***"



def enc_af(text):
    temp = ""
    for char in text:
        temp += str(ord(char)^62) + " "

    return temp


f.write(enc_af(secret))
