
# ⌨️ Python Keylogger: Event Listening Practice

A simple Python-based tool that captures keyboard inputs and saves them to a local text file. This project demonstrates the use of the `pynput` library for monitoring hardware events and handling file I/O (Input/Output).

> [!WARNING]
> **DISCLAIMER:** This project is created for **educational and ethical security testing purposes only**. Using this tool to monitor someone's activity without their explicit permission is illegal and unethical.

## 📌 Project Overview

This script acts as a background listener that records every keystroke made by the user. It distinguishes between alphanumeric keys (letters/numbers) and special keys (Space, Enter, Esc), formatting them into a readable text file.

## 🛠️ Key Features & Concepts

### 1. Hardware Event Listening

Using the `pynput.keyboard` module, the script creates a **Listener** thread that "hooks" into the operating system's keyboard events.

* `on_press`: Triggered when a key is pushed down.
* `on_release`: Triggered when a key is lifted.

### 2. Exception Handling (`AttributeError`)

In Python, `pynput` treats normal characters and special keys differently.

* **Alphanumeric keys** have a `.char` attribute.
* **Special keys** (like Shift or Ctrl) do not, so we use `try/except` blocks to prevent the program from crashing and to handle formatting manually.

### 3. File Handling (Append Mode)

The script uses the `"a"` (append) mode to open the log file:

```python
with open(log_file, "a") as f:

```

This ensures that new keystrokes are added to the end of the file rather than overwriting previous data.

## 📂 Project Structure

* `keylogger.py`: The main Python script containing the listener logic.
* `keylogs.txt`: The automatically generated file where your keystrokes are stored.

## 🚀 How to Run

1. **Install the library:**
Open your terminal and run:
```bash
pip install pynput

```


2. **Run the script:**

```bash
    python keylogger.py
    ```
3.  **Stop the program:**
    Press the `Esc` key to stop the listener and close the script.

## 💡 Technical Takeaways
*   **Context Managers:** Using the `with` statement ensures that files and listeners are closed properly even if an error occurs.
*   **Thread Joining:** `listener.join()` keeps the main script running so that it stays active until the `on_release` function returns `False`.
*   **Data Formatting:** Learning how to map raw hardware input into human-readable strings (e.g., converting `Key.enter` to a new line `\n`).

---

**Safe Coding Practice:** Always be transparent about the tools you build! 💻

```
