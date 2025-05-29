# 📡 ESP32-C3 XIAO Captive Portal

A small **captive portal** made with an ESP32-C3 XIAO
When someone connects to the Wi-Fi network, a custom web page is shown automatically.

## 🚀 Features

- Creates a Wi-Fi Access Point
- Redirects all requests to a local HTML page
- Fully offline (no internet needed)
- Lightweight and easy to flash

## 🧰 Requirements

- [Seeed Studio XIAO ESP32-C3](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/)
- Arduino IDE + ESP32 board support

## 🔌 Arduino Libraries

- `WiFi.h`
- `WebServer.h`
- `DNSServer.h`

## ⚙️ How to Use

1. Open the `.ino` file in Arduino IDE  
2. Select the board: **ESP32C3 Dev Module**
3. Flash the code  
4. Connect to Wi-Fi `name`
5. The custom page will show up

## 📝 Notes

This project is great for learning about:
- Captive portals
- Local DNS redirection
- Hosting pages from microcontrollers

