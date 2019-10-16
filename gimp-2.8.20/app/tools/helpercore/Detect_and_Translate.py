from PIL import Image
import pytesseract
from googletrans import Translator

import os 
dir_path = os.path.dirname(os.path.realpath(__file__))

# for pre-processing
import cv2
import numpy as np

# Grayscale image
img = Image.open(dir_path + '/temp/talkbox.jpg').convert('L')
img = cv2.adaptiveThreshold(np.array(img),255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,11,2)
# ret,img = cv2.threshold(np.array(img), 125, 255, cv2.THRESH_BINARY)
img = cv2.dilate(img,(3,3))

# Older versions of pytesseract need a pillow image
# Convert back if needed
# img = Image.fromarray(img.astype(np.uint8))

# print(pytesseract.image_to_string(img, lang = 'jpn'))
# cv2.imshow('test input', img)
# cv2.waitKey(0)



# img = Image.open(dir_path + "/temp/talkbox.jpg")

# English: 'eng', Japanese: 'jpn', Chinese:'chi_sim', 'chi_tra'
text = pytesseract.image_to_string(img, lang = 'chi_tra')
# https://askubuntu.com/questions/793634/how-do-i-install-a-new-language-pack-for-tesseract-on-16-04


text = text.replace("\n","")

# print(text)

#output file
text_file= open(dir_path + "/temp/Extracted_words.txt","w+")
text_file.truncate(0)
text_file.write(text)
text_file.close()

translator = Translator(service_urls=[
      'translate.google.com',
      'translate.google.co.kr',
    ])

# English: 'en', Japanese: 'ja', Chinese:'zh-cn'(simplified)','zh-tw'(traditional)
translation = translator.translate(text, dest='en')
# https://py-googletrans.readthedocs.io/en/latest/

print(translation.origin, '->', translation.text)

#output file
text_file= open(dir_path + "/temp/Translated.txt","w+")
text_file.truncate(0)
text_file.write(translation.text)
text_file.close()
