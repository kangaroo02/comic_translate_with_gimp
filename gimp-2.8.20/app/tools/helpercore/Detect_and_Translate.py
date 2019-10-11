from PIL import Image
import pytesseract
from googletrans import Translator



im = Image.open("/home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/temp/talkbox.jpg")

text = pytesseract.image_to_string(im, lang = 'jpn')

text = text.replace("\n","")

#print(text)

#output file
text_file= open("/home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/temp/Extracted_words.txt","w+")
text_file.write(text)
text_file.close()

translator = Translator(service_urls=[
      'translate.google.com',
      'translate.google.co.kr',
    ])

translation = translator.translate(text, dest='zh-tw')
#print(translation.origin, '->', translation.text)

#output file
text_file= open("/home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/temp/Translated.txt","w+")
text_file.write(translation.text)
text_file.close()
