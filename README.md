# 🔧 Замена заставки на паяльнике Sequre S99

![Изображение паяльника](photo.jpg)

## 📋 Инструкция по замене изображения на экране паяльника:

---

### 🅰️ Способ А — Использование `image_to_data.html`

Чтобы заменить картинку на экране паяльника, выполните следующие шаги:

✅ 1. Откройте файл **`image_to_data.html`** в браузере  
✅ 2. Нарисуйте изображение, которое хотите установить  
✅ 3. Нажмите кнопку **Copy**, чтобы скопировать массив данных  
✅ 4. Запустите **`make_firmware.exe`**  
✅ 5. Вставьте скопированный массив в консоль и нажмите **Enter**

📦 Если всё прошло успешно, вы увидите сообщение:  
**✅ New firmware file created successfully! Press any key to exit**

📁 В папке появится файл **`new_firmware.hex`**

---

### 🔌 Прошивка паяльника

✅ 1. Зажмите первую кнопку на паяльнике  
✅ 2. Подключите его к компьютеру  
✅ 3. Перетащите файл **`new_firmware.hex`** на устройство  
⌛ Дождитесь завершения прошивки

---

### 🅱️ Способ Б — Использование `bitmaper.html` от AlexGyver

Этот способ позволяет использовать изображение (например, фото) в качестве загрузочной картинки.

#### 📷 Шаги:

✅ 1. Откройте файл **`bitmaper.html`** в браузере  
✅ 2. В разделе **Процесс** выберите `8x Vertical Col`  
✅ 3. Загрузите изображение и настройте яркость/контраст  
✅ 4. Нажмите **"Копировать"**, чтобы скопировать массив  
✅ 5. Запустите **`make_data.exe`**  
✅ 6. Вставьте скопированный текст в консоль и дважды нажмите **Enter**  
✅ 7. Полученный массив данных используйте в **`make_firmware.exe`**

---

## 🗂️ Важно

- Оригинальный файл прошивки **`S99_V1.08.hex`** должен находиться в одной папке с **`make_firmware.exe`**
- Все изменения происходят на ваш страх и риск 😄
- Только **Secure S99**

---

## 💬 Благодарю [AlexGyver](https://github.com/AlexGyver) за **bitmaper.html**
