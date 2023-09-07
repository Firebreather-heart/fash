import os
import sys


def change_directory(path):
    try:
        os.chdir(path)
    except FileNotFoundError:
        print(f"cd: {path}: No such file or directory")
        sys.exit(1)
    except NotADirectoryError:
        print(f"cd: {path}: Not a directory")
        sys.exit(1)
    except PermissionError:
        print(f"cd: {path}: Permission denied")
        sys.exit(1)


def main():
    if len(sys.argv) != 2:
        print("Usage: python cd_program.py <directory>")
        sys.exit(1)

    path = sys.argv[1]

    if path == "~":
        path = os.path.expanduser("~")
    elif path == "-":
        path = os.environ.get("OLDPWD", "")

    change_directory(path)
    print(os.getcwd())


if __name__ == "__main__":
    main()
