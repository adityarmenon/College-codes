import requests
import tldextract

url = input("Enter the URL to check: ")
ext = tldextract.extract(url)
tld = ext.suffix
try:
    if tld in ('onion', 'i2p', 'bit'):
        print("This is a dark web URL.")
    elif requests.get(url).status_code == 200:
        print("This is a surface web URL.")
    else:
        print("This URL is not accessible.")
except:
    print("Error")