# sfiii-decomp

A project aimed at decompiling Street Fighter III.

## Working with splat

1. Install dependencies.

    ```bash
    python3 -m venv venv
    source venv/bin/activate
    python -m pip install -r requirements.txt
    ```

2. Run `splat`.

    ```bash
    python -m splat split config/sfiii.yaml
    ```
