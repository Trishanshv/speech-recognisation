##🎤 Speech Recognition (Whisper + SpeechRecognition)

This project is a speech-to-text recognizer built using OpenAI Whisper
, PyTorch
, and SpeechRecognition.

It is designed as the core component of a larger file assistant project, but can also be used as a standalone speech recognizer.
---
##✨ Features

🎧 Listens to live audio from your microphone.

⚡ Uses Whisper (base model) with GPU acceleration (if available).

📄 Transcribes speech into text in real time.

🛠 Simple and modular — can be extended into assistants or other projects.
---
##📂 Project Structure
```
speech-recognisation/
│
├── speech.py        # Main script: listens via microphone & transcribes speech
├── temp.wav         # Temporary audio file saved during recognition
├── check.cpp        # (Currently unused, placeholder for future extensions)
```
---
##🔧 Installation
```
1. Clone the repository
git clone https://github.com/Trishanshv/speech-recognisation.git
cd speech-recognisation

2. Create a virtual environment (recommended)
python -m venv venv
source venv/bin/activate   # On Linux/Mac
venv\Scripts\activate      # On Windows

3. Install dependencies
pip install torch torchvision torchaudio
pip install git+https://github.com/openai/whisper.git
pip install SpeechRecognition pyaudio
```

⚠️ Note:

pyaudio may require additional system setup (portaudio).
If GPU (CUDA) is available, Whisper will run much faster.

##▶️ Usage

Run the main script:

python speech.py


The program will listen continuously from your default microphone.

After each recording, it will print the recognized text:

Listening...
You said: open my documents folder


You can later hook this output into your assistant logic.

##🚀 Future Plans

Add file assistant integration (process spoken commands).

Improve accuracy by experimenting with larger Whisper models.

Add support for multiple languages.

🤝 Contribution

Feel free to fork this repo, open issues, or submit pull requests with improvements.
