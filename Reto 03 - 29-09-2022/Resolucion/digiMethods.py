import urllib.request
import requests
import os
from PIL import Image

class DigiMethods:
    def retrieveDigimonPic(name):
        url = "https://digimon-api.com/images/digimon/w/" + name + ".png"
        response = requests.get(url)
        test = response.status_code
        print(response.status_code)
        if response.status_code == 200:
            urllib.request.urlretrieve(url, name + ".png")
            if DigiMethods.checkForFile(name + ".png"):
                return "Datos guardados"
            else:
                return "No ha sido posible crear el archivo"
        else:
            return "Digimon no encontrado"

    def retrieveDigimonPicURL(JSONurl):
        if JSONurl == "No se ha encontrado el Digimon":
            return "No se ha encontrado el Digimon"

        response = requests.get(JSONurl)
        name = DigiMethods.parseURL(JSONurl)
        if response.status_code == 200:
            name = name.replace("_", " ")
            urllib.request.urlretrieve(JSONurl, name)
            DigiMethods.openImage(name)
            if DigiMethods.checkForFile(name):
                return "Datos guardados"
            else:
                return "No ha sido posible crear el archivo"
        else:
            return "Digimon no encontrado"

    def retrieveJSON(name):
        url = "https://www.digi-api.com/api/v1/digimon/" + name
        response = requests.get(url)
        if response.status_code == 200:
            responseJSON = response.json()
            imageURL = responseJSON['images']
            imageURL = imageURL[0]['href']
            return imageURL
        else:
            return "No se ha encontrado el Digimon"

    def openImage(path):
        image = Image.open(path)
        image.show()

    def checkForFile(path):
        if os.path.exists(path):
            return True
        else:
            return False
    
    def parseURL(imageURL):
        name = imageURL.split(sep="/")
        return name[-1]
