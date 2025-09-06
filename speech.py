import whisper
import torch
import speech_recognition as sr

# Check if GPU is available
device = "cuda" if torch.cuda.is_available() else "cpu"
model = whisper.load_model("base", device=device)

# Initialize speech recognizer
recognizer = sr.Recognizer()
mic = sr.Microphone()

def listen_and_transcribe():
    with mic as source:
        recognizer.adjust_for_ambient_noise(source)
        print("Listening...")
        audio = recognizer.listen(source)
    
    with open("temp.wav", "wb") as f:
        f.write(audio.get_wav_data())

    result = model.transcribe("temp.wav")
    print("You said:", result["text"])  # Later, we’ll process this as a command

# Run continuously
while True:
    listen_and_transcribe()
