import telebot
import random
import requests, re
from bs4 import BeautifulSoup

token = '5850124671:AAEBMQop7K7efKy-hvp5k-lb-hiX9YnpdDA'
bot = telebot.TeleBot(token)


@bot.message_handler(commands=['start', 'help'])
def send_welcome(message):
    welcome_text = '''Привет! Я универсальный, могу отправить тебя разные полезности! Что ты хочешь увидеть?'''

    keyboard = telebot.types.ReplyKeyboardMarkup(row_width=2, resize_keyboard=True, one_time_keyboard=False)
    button1 = telebot.types.KeyboardButton('Факт')
    button2 = telebot.types.KeyboardButton('Стишок')
    button3 = telebot.types.KeyboardButton('Котики')
    button4 = telebot.types.KeyboardButton('Стикер')
    button5 = telebot.types.KeyboardButton('Песенка')
    button6 = telebot.types.KeyboardButton('Игры')
    button7 = telebot.types.KeyboardButton('Подарок')
    keyboard.add(button1, button2, button3, button4, button5, button6, button7)
    bot.send_message(message.chat.id, welcome_text, reply_markup=keyboard)

@bot.message_handler(commands=['fact'])
def send_fact(message):
    response = requests.get('https://i-fakt.ru/').content
    html = BeautifulSoup(response, 'html.parser')
    fact = random.choice(html.find_all(class_='p-2 clearfix'))
    fact_link =  fact.a.attrs['href']
    fact_text = fact.text
    bot.send_message(message.chat.id, fact_link + fact_text)

@bot.message_handler(commands=['cat'])
def send_cat(message):
    cat_number = random.randint(1, 10)
    cat_img = open(f'img/{cat_number}.jpg', 'rb')
    bot.send_photo(message.chat.id, cat_img)

@bot.message_handler(commands=['music'])
def send_music(message):
    music = open('happy.mp3', 'rb')
    bot.send_audio(message.chat.id, music)

@bot.message_handler(commands=['sticker'])
def send_sticker(message):
    sticker = open('dude.png', 'rb')
    bot.send_sticker(message.chat.id, sticker)

@bot.message_handler(commands=['poem'])
def send_poem(message):
    poem_text = "Муха села на варенье, вот и все стихотворенье..."
    bot.send_message(message.chat.id, poem_text)
    keyboard = telebot.types.InlineKeyboardMarkup(row_width=1)
    button_url = telebot.types.InlineKeyboardButton("Перейти", url='https://stihi.ru/')
    keyboard.add(button_url)
    bot.send_message(message.chat.id,  'Больше стихов по ссылке ниже', reply_markup=keyboard)



# # №1
# # Во что поиграть

# @bot.message_handler(commands=['poem'])
# def send_game(message):



# # №2
# # Во что поиграть по жанрам

@bot.message_handler(commands=['game'])
def send_play(message):
    game = 'Выбери в какой жанр вы бы хотели поиграть: '
    keyboard = telebot.types.ReplyKeyboardMarkup(row_width=2, resize_keyboard=True, one_time_keyboard=False)
    button_1 = telebot.types.KeyboardButton('Гонки')
    button_2 = telebot.types.KeyboardButton('Инди')
    button_3 = telebot.types.KeyboardButton('Казуальная игра')
    button_4 = telebot.types.KeyboardButton('ММО')
    button_5 = telebot.types.KeyboardButton('Приключение')
    button_6 = telebot.types.KeyboardButton('Ролевая игра')
    button_7 = telebot.types.KeyboardButton('Симулятор')
    button_8 = telebot.types.KeyboardButton('Спортивная игра')
    button_9 = telebot.types.KeyboardButton('Стратегия')
    button_10 = telebot.types.KeyboardButton('Экшен')
    keyboard.add(button_1, button_2, button_3, button_4, button_5, button_6, button_7, button_8, button_9, button_10)
    bot.send_message(message.chat.id, game, reply_markup=keyboard)
    

    if game == 'Гонки':
        race= re.findall('<span class="title"*>(.+)</span>',
        requests.get('https://store.steampowered.com/search/?term=%D0%93%D0%BE%D0%BD%D0%BA%D0%B8').text, flags=re.I)
        rac = random.choice(race)
        bot.send_message(message.chat.id, rac)
    elif game == 'Инди':
        indi = re.findall('<span class="title"*>(.+)</span>',
        requests.get('https://store.steampowered.com/search/?term=%D0%98%D0%BD%D0%B4%D0%B8').text, flags=re.I)
        ind = random.choice(indi)
        bot.send_message(message.chat.id, ind)
    elif game == 'Казуальная игра':
        casual = re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%9A%D0%B0%D0%B7%D1%83%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5+%D0%B8%D0%B3%D1%80%D1%8B').text, flags=re.I)
        cas = random.choice(casual)
        bot.send_message(message.chat.id, cas)
    elif game == 'ММО':
        mmo= re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%9C%D0%9C%D0%9E').text, flags=re.I)
        mm = random.choice(mmo)
        bot.send_message(message.chat.id, mm)
    elif game == 'Приключение':
        adventure= re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%9F%D1%80%D0%B8%D0%BA%D0%BB%D1%8E%D1%87%D0%B5%D0%BD%D0%B8%D1%8F').text, flags=re.I)
        adv = random.choice(adventure)
        bot.send_message(message.chat.id, adv)
    elif message.text.strip() == 'Ролевая игра':
        role=re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%AD%D0%BA%D1%88%D0%B5%D0%BD').text, flags=re.I)
        rol = random.choice(role)
        bot.send_message(message.chat.id, rol)
    elif message.text.strip() == 'Симулятор':
        stimulator= re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%A1%D0%B8%D0%BC%D1%83%D0%BB%D1%8F%D1%82%D0%BE%D1%80').text, flags=re.I)
        sti = random.choice(stimulator)
        bot.send_message(message.chat.id, sti)
    elif message.text.strip() == 'Спортивная игра':
        sport= re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%A1%D0%BF%D0%BE%D1%80%D1%82').text, flags=re.I)
        spo =random.choice(sport)
        bot.send_message(message.chat.id, spo)
    elif message.text.strip() == 'Стратегия':
        strategy= re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%A1%D1%82%D1%80%D0%B0%D1%82%D0%B5%D0%B3%D0%B8%D1%8F').text, flags=re.I)
        strat=random.choice(strategy)
        bot.send_message(message.chat.id, strat)
    elif message.text.strip() == 'Экшен':
        action = re.findall('<span class="title"*>(.+)</span>', 
        requests.get('https://store.steampowered.com/search/?term=%D0%AD%D0%BA%D1%88%D0%B5%D0%BD').text, flags=re.I)
        act = random.choice(action)
        bot.send_message(message.chat.id, act)

    
    keyboard = telebot.types.ReplyKeyboardMarkup(row_width=2, resize_keyboard=True, one_time_keyboard=False)
    button1 = telebot.types.KeyboardButton('Факт')
    button2 = telebot.types.KeyboardButton('Стишок')
    button3 = telebot.types.KeyboardButton('Котики')
    button4 = telebot.types.KeyboardButton('Стикер')
    button5 = telebot.types.KeyboardButton('Песенка')
    button6 = telebot.types.KeyboardButton('Игры')
    button7 = telebot.types.KeyboardButton('Подарок')
    keyboard.add(button1, button2, button3, button4, button5, button6, button7)
    bot.send_message(message.chat.id, game, reply_markup=keyboard)
    


# # №3
# # Какая-то функция

@bot.message_handler(commands=['gift'])
def send_gift(message):
    mess = '''Я создала собственные стикеры💓 
Теперь ты их можешь использовать в телеграмме'''
    bot.send_message(message.chat.id, mess)
    keyboard = telebot.types.InlineKeyboardMarkup(row_width=1)
    button_ur = telebot.types.InlineKeyboardButton("Скачать", url='')
    keyboard.add(button_ur)
    bot.send_message(message.chat.id,  'Скачать стикерпак по ссылке ниже', reply_markup=keyboard)



@bot.message_handler(content_types=['text'])
def answer(message):
    if message.text.strip() == 'Факт':
        send_fact(message)
    elif message.text.strip() == 'Котики':
        send_cat(message)
    elif message.text.strip() == 'Песенка':
        send_music(message)
    elif message.text.strip() == 'Стикер':
        send_sticker(message)
    elif message.text.strip() == 'Стишок':
        send_poem(message)
    elif message.text.strip() == 'Игры':
        send_play(message)
    elif message.text.strip() == 'Подарок':
        send_gift(message)



bot.infinity_polling()