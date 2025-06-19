import speech_recognition as sr
import serial
import time

arduino = serial.Serial('COM3', 9600)  # Change COM3 to your port
time.sleep(2)

recognizer = sr.Recognizer()

def listen_and_open():
    with sr.Microphone() as source:
        print("Listening for command...")
        audio = recognizer.listen(source)
        try:
            command = recognizer.recognize_google(audio)
            print("You said:", command)
            if "open" in command.lower():
                arduino.write(b'1')  # Send signal to Arduino
                print("Signal sent to open gate.")
        except sr.UnknownValueError:
            print("Could not understand.")
        except sr.RequestError:
            print("Speech service down.")

while True:
    listen_and_open()
