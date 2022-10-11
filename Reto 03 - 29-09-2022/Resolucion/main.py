"""

Un amigo tuyo es un gran fanático de los Digimon. Para su cumpleaños, te gustaría hacer un lector de tarjetas con una pantalla TFT. Al acercar una tarjeta, la pantalla mostrará el Digimon elegido.

Para eso, necesitas una función que obtenga la imagen de un Digimon a partir de su nombre.

Buscando en Internet, has encontrado un API para Digimon (digimon-api.com), que dispone de todas las imágenes de Digimon.

La URL es la siguiente,
        https://digimon-api.com/images/digimon/w/__digimon__.png

Donde,
- digimon es el nombre de un Digimon

Por ejemplo https://digimon-api.com/images/digimon/w/Guilmon.png

Se pide hacer una función o pequeño script que, dado el nombre de un Digimon, descargue su imagen desde "digimon-api.com" a una carpeta local.

==== BONUS PACK ====
Para nota, quien quiera, puede ampliar con el siguiente ejercicio:

Obtener previamente la URL de la imagen del Digimon a través del JSON devuelto por el API según URL
        https://www.digi-api.com/api/v1/digimon/__digimon__

Por ejemplo, https://www.digi-api.com/api/v1/digimon/Guilmon resulta en el siguiente JSON,
{
    "id": 543,
    "name": "Guilmon",
    "xAntibody": false,
    "images": [
        {
            "href": "https://digimon-api.com/images/digimon/w/Guilmon.png",
            "transparent": false
        }
    ],
    ...
}

"""
import digiMethods


def digi():
    digimon = input('Pon el nombre de un Digimon:\n')
    image = digiMethods.DigiMethods.retrieveDigimonPicURL(JSONurl=digiMethods.DigiMethods.retrieveJSON(name=digimon))
    print(image)

if __name__ == '__main__':
    digi()
