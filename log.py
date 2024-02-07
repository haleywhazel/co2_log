import csv
import serial

def read_serial(port, baudrate):
    filename = input("Save as <insert filename>.csv: ") + ".csv"
    print("Saving data to " + filename + " ...")

    f = open(filename, "x")
    f.close()
    ser = serial.Serial(port, baudrate, timeout=0.5)

    while True:
        data = ser.readline().decode().strip()
        if data and not data[0].isalpha():
            f = open(filename, "a")
            f.write(data + "\n")
            f.close()
            print(data)


if __name__ == '__main__':
    read_serial('COM4', 9600)