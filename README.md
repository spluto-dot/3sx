# sfiii-decomp

Decompilation of Street Fighter III (PS2).

## Building

0. (Optional) This repo assumes a Linux environment. If you're on macOS use Docker with the provided `Dockerfile`.

1. Install dependencies.

    ```bash
    pip install -r requirements.txt
    sudo apt-get update && sudo apt-get install -y $(cat tools/requirements-debian.txt)
    make setup_tools
    ```

2. Put `SLPM_656.21` from your copy of the game in the root folder.

3. Run `splat`.

    ```bash
    tools/split.sh
    ```

4. Build. If everything's okay you'll see the message `Files match ✅`.

    ```bash
    make
    ```

5. (Optional) Run the exe in [PCSX2](https://github.com/PCSX2/pcsx2)

    ```bash
    /path/to/PCSX2 -elf build/SLPM_656.21 -fastboot -- /path/to/SFIII.iso
    ```
