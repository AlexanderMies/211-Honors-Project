#Alexander Mies
#CSC 211H w/ Dr. Ahzar
#5/19/2021

from os import system
import requests as req
from bs4 import BeautifulSoup
import time
import datetime
from html.parser import HTMLParser
import smtplib

# Opening the html text file in the current directory
HTMLFile = open("htmlFile.txt","r")

# Creating a BeautifulSoup object and specifying the parser
Parse = BeautifulSoup(HTMLFile,'html')
  
# Traverse HTML and parse the result URLS
myURLS = Parse.find_all("a",{"class":"result__url"})

# Formatting result tags and pushing them into urls[]
idx = 1
urls = []
for tag in myURLS:
    item = f'Link {idx}:{tag.text}'
    print(item)
    urls.append(item)
    idx+=1

# define send mail function
def send_mail():
    # Authenticate app
    server = smtplib.SMTP('smtp.gmail.com', 587)
    
    # handshake and authenticate server
    server.ehlo()
    server.starttls()
    server.ehlo()

    # App login and password with API key
    server.login('alexmies95@gmail.com', 'mpccxixozwvfkbyq')

    # Email contents subject/body
    subject = 'Links for Recipes Requested!'
    body = urls

    # msg to pass in to server arg
    msg = f'Subject: {subject}\n\n{body}'


    server.sendmail(
        'alexmies95@gmail.com', # Sender
        'alexmies95@gmail.com', # Recipient
        msg
    )

    print('URLS have been sent successfully!')

    server.quit()

# function call to send email with recipe urls
send_mail()

