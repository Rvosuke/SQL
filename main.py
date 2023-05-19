from PySide6.QtWidgets import QApplication, QMainWindow
from back.models import create_tables


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # TODO: Create your UI here


def main():
    create_tables()

    app = QApplication([])

    window = MainWindow()
    window.show()

    app.exec()


if __name__ == "__main__":
    main()
