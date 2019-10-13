from PIL import Image
import pytesseract
from googletrans import Translator

import os 
dir_path = os.path.dirname(os.path.realpath(__file__))

# # for pre-processing
# import cv2
# import numpy as np

# # Grayscale image
# img = Image.open(dir_path + '/temp/talkbox.jpg').convert('L')
# ret,img = cv2.threshold(np.array(img), 125, 255, cv2.THRESH_BINARY)

# # Older versions of pytesseract need a pillow image
# # Convert back if needed
# # img = Image.fromarray(img.astype(np.uint8))

# # print(pytesseract.image_to_string(img, lang = 'jpn'))
# cv2.imshow('test input', img)
# cv2.waitKey(0)



im = Image.open(dir_path + "/temp/talkbox.jpg")

text = pytesseract.image_to_string(im, lang = 'jpn')

text = text.replace("\n","")

# print("思い 小さな想い")
# print(text)

#output file
text_file= open(dir_path + "/temp/Extracted_words.txt","w+")
text_file.write(text)
text_file.close()

translator = Translator(service_urls=[
      'translate.google.com',
      'translate.google.co.kr',
    ])

translation = translator.translate(text, dest='zh-tw')
#print(translation.origin, '->', translation.text)

#output file
text_file= open(dir_path + "/temp/Translated.txt","w+")
text_file.write(translation.text)
text_file.close()
