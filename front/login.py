from PySide6.QtWidgets import QMainWindow, QLineEdit, QPushButton, QLabel, QVBoxLayout, QWidget
from PySide6.QtCore import Qt
from back.database import create_connection, execute_query


class LoginWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Login")

        self.username_input = QLineEdit()
        self.password_input = QLineEdit()
        self.password_input.setEchoMode(QLineEdit.Password)

        self.login_button = QPushButton("Login")
        self.login_button.clicked.connect(self.login)

        self.error_label = QLabel()
        self.error_label.setAlignment(Qt.AlignCenter)

        layout = QVBoxLayout()
        layout.addWidget(self.username_input)
        layout.addWidget(self.password_input)
        layout.addWidget(self.login_button)
        layout.addWidget(self.error_label)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

    def login(self):
        username = self.username_input.text()
        password = self.password_input.text()

        connection = create_connection()
        cursor = execute_query(connection,
                               f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'")
        user = cursor.fetchone()

        if user is None:
            self.error_label.setText("Invalid username or password.")
        else:
            # TODO: Show the main window for this user
            pass
