import pyodbc

#Коннект с БД
conn = pyodbc.connect(r'Driver={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\Users\BRDen\Desktop\Vovchik\Vovich.accdb;')
cursor = conn.cursor()

# name = "pedik"
# date = "2002-11-10"
# calcs = 555

# # #INSERT
# cursor.execute("INSERT INTO UserData(User, User_Date, ) VALUES(?, ?, ?)", (name, date, calcs)) #ввод данных в БД из переменных
# cursor.commit()

# #SELECT
# cursor.execute("SELECT * FROM UserData")


# #user_name = input("Введите пользователя: ")
# for row in cursor.fetchall():
#     print(row.User, row.User_Date, row.Calc)

# cursor.commit()


cursor.execute("DELETE FROM UserData WHERE User = (?)", (Id))

conn.commit()


