from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.configure(background='#696969')
image = PhotoImage( file = "circuit_4.png" )

F_low = StringVar(); R_para = StringVar(); V_para = StringVar(); R_ser = StringVar(); V_ser = StringVar(); R_div = StringVar(); V_div = StringVar();
F_low.set(400); R_para.set('50, 100, 1000'); V_para.set(5); R_ser.set('150, 200, 10000'); V_ser.set(10); R_div.set('50, 50, 100'); V_div.set(10)
image_label = Label(image = image).grid(row = 0, padx=20, pady=20, columnspan=7)

Section_para= Label(root, bg = '#20B2AA', text = "Circuito en paralelo", width =40).grid(row = 1, column = 0,  padx=2, pady=2, columnspan=2)
R_paralelo = Label(root, text = "Resistencias:").grid(row = 2, column = 0,  padx=2, pady=2)
R_parelelo_ =Entry(root, textvariable = R_para, width =20).grid(row = 2, column = 1)
V_paralelo = Label(root, text = "Voltaje:").grid(row = 3, column = 0,  padx=2, pady=2)
V_parelelo_ =Entry(root, textvariable = V_para, width =10).grid(row = 3, column = 1)
Calcu_para = Button(root, bg ='#483D8B', fg='white', text = "Calcular", width =15).grid(row = 4, column = 1, padx=2, pady=2)
Res___para = Label(root, bg = '#20B2AA', text = "Resultado").grid(row = 5, column = 0,  padx=2, pady=2)
Resul_para = Label(root, bg = '#20B2AA', text = "").grid(row = 5, column = 1,  padx=2, pady=2)

Section_serie= Label(root, bg = '#20B2AA', text = "Circuito en serie", width =40).grid(row = 1, column = 2,  padx=2, pady=2, columnspan=2)
R_serie  = Label(root, text = "Resistencias:").grid(row = 2, column = 2,  padx=2, pady=2)
R_serie_ =Entry(root, textvariable = R_ser, width =20).grid(row = 2, column = 3)
V_serie  = Label(root, text = "Voltaje:").grid(row = 3, column = 2,  padx=2, pady=2)
V_serie_ = Entry(root, textvariable = V_ser, width =10).grid(row = 3, column = 3)
Calcu_se = Button(root, bg ='#483D8B', fg='white', text = "Calcular", width =15).grid(row = 4, column = 3, padx=2, pady=2)
Res___se = Label(root, bg = '#20B2AA', text = "Resultado").grid(row = 5, column = 2,  padx=2, pady=2)
Resul_se = Label(root, bg = '#20B2AA', text = "").grid(row = 5, column = 3,  padx=2, pady=2)

Section_div= Label(root, bg = '#20B2AA', text = "Divisor de voltaje", width =40).grid(row = 1, column = 4,  padx=2, pady=2, columnspan=2)
R_divisor  = Label(root, text = "Resistencias:").grid(row = 2, column = 4,  padx=2, pady=2)
R_divisor_ =Entry(root, textvariable = R_div, width =20).grid(row = 2, column = 5)
V_divisor  = Label(root, text = "Voltaje:").grid(row = 3, column = 4,  padx=2, pady=2)
V_divisor_ = Entry(root, textvariable = V_div, width =10).grid(row = 3, column = 5)
Calcu_di = Button(root, bg ='#483D8B', fg='white', text = "Calcular", width =15).grid(row = 4, column = 5, padx=2, pady=2)
Res___di = Label(root, bg = '#20B2AA', text = "Resultado").grid(row = 5, column = 4,  padx=2, pady=2)
Resul_di = Label(root, bg = '#20B2AA', text = "").grid(row = 5, column = 5,  padx=2, pady=2)

Erase_button = Button(root, bg ='#008B8B', fg='white', text = "Limpiar valores", width =15).grid(row = 8, column = 0, padx=2, pady=2)
my_button_close = Button(root, text="Cerrar ventana", bg ='red', fg='white', width =20).grid(row = 9, column = 0) 
root.mainloop()