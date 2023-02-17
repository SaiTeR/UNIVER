# Подключение нужных библиотек
from ast import Global
import time
import logging
import random
from aiogram import Bot, Dispatcher, executor, types
from datetime import datetime
#import pandas as pd 
#import xlwt
import pyodbc

API_TOKEN = '1041112364:AAHqcazg_JCUziL6ty-tJFwhvBsaoxkNmmE'

#Подключние к файлу БД
conn = pyodbc.connect(r'Driver={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\BRDen\Desktop\Vovchik\Vovich.accdb;')
cursor = conn.cursor()

# Настройка ведения журнала
logging.basicConfig(level=logging.INFO)

# Инициализировать бота и диспетчера
bot = Bot(token=API_TOKEN)
dp = Dispatcher(bot)



# Создаём функции для обработки сообщений пользователя с помощью декораторов
# функция для приветствия пользователя6
@dp.message_handler(commands=['start'])
async def send_welcome(message: types.Message):
    global df_marks, writer
    pul = random.randint(40, 100)
    user_id = message.from_user.id
    Id = (f'{user_id}')
    user_name = message.from_user.username
    user_full_name = message.from_user.full_name
    logging.info(f'{user_id= } {user_name=} {user_full_name=} {time.asctime()}')

    # df_marks = pd.DataFrame({'Date': [datetime.now()], 'Pulse': pul}) 
    # writer = pd.ExcelWriter('Excel.xlsx', mode = 'a', if_sheet_exists = 'overlay') 
    # df_marks.to_excel(writer, str(Id), index=False) 
    # writer.save()  

  
  # вывод сообщения в телеграмме
    await message.answer(f"Привет, {user_full_name}! Меня зовут Hero, я тебе помогу отслеживать пульс!❤️")
    


@dp.message_handler(commands=['delete'])
async def send_welcome(message: types.Message):
    #global df_marks, writer
    #pul = random.randint(40, 100)
    user_id = message.from_user.id
    Id = (f'{user_id}')
    
    cursor.execute("DELETE FROM UserData WHERE User = (?)", (Id))
    conn.commit()

    
# функция для обработки команды help и помощи пользователю
@dp.message_handler(commands=['help'])
async def send_welcome(message: types.Message):
   # вывод сообщения в телеграмме
    await message.answer("Извините, если возникли неполадки🥺\nБот находится в разработке")



# функция для обработки команды pulse и вывода пульса пользователя и занесения в базу данных
@dp.message_handler(commands=['pulse'])
async def send_welcome(message: types.Message):
    user_id = message.from_user.id
    Id = (f'{user_id}')
    pul = random.randint(40, 100)
    # df_marks = pd.DataFrame({'Date': [datetime.now()], 'Pulse': pul}) 
    # writer = pd.ExcelWriter('Excel.xlsx', mode = 'a', if_sheet_exists = 'overlay') 
    # df_marks.to_excel(writer, sheet_name = str(Id), index=False) 


    #ввод данных в БД из переменных
    cursor.execute("INSERT INTO UserData(User, User_Date, Pulse) VALUES(?, ?, ?)", (Id, datetime.now(), pul))
    cursor.commit()

    # вывод сообщения в телеграмме
    await message.answer(f"Ваш пульс: {pul}")
    if 80 <=pul<= 100:
       # вывод сообщения в телеграмме
        await message.answer("У вас повышенное сердцебиение!")
    elif pul<= 80:
      # вывод сообщения в телеграмме
        await message.answer("Сердцебиение в норме!")
  
  
    #writer.save() 



# функция для обработки команды history и вывода данных из базы
@dp.message_handler(commands=['history'])
async def send_welcome(message: types.Message):
    user_id = message.from_user.id
    Id = (f'{user_id}')

    #data = pd.read_excel('Excel.xlsx', str(Id))
    data = "Дата \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tПульс \n"

    cursor.execute("SELECT * FROM UserData")
    for row in cursor.fetchall():
        if row.User == Id:
            data += datetime.strftime(row.User_Date, "%d.%m.%Y %H:%M") + "\t\t\t\t" + str(row.Pulse) + "\n"

    await message.answer("История измерений:")
    await message.answer(data)


if __name__ == '__main__':
    executor.start_polling(dp, skip_updates=True)