from back.database import create_connection, execute_query


def create_tables():
    connection = create_connection()

    create_user_table = """
    CREATE TABLE IF NOT EXISTS users (
        id INT AUTO_INCREMENT PRIMARY KEY,
        username VARCHAR(40) NOT NULL UNIQUE,
        password VARCHAR(40) NOT NULL,
        is_admin BOOLEAN NOT NULL DEFAULT FALSE
    )
    """
    execute_query(connection, create_user_table)

    create_book_table = """
    CREATE TABLE IF NOT EXISTS books (
        id INT AUTO_INCREMENT PRIMARY KEY,
        title VARCHAR(100) NOT NULL,
        author VARCHAR(40) NOT NULL,
        is_borrowed BOOLEAN NOT NULL DEFAULT FALSE
    )
    """
    execute_query(connection, create_book_table)

    create_borrow_table = """
    CREATE TABLE IF NOT EXISTS borrows (
        id INT AUTO_INCREMENT PRIMARY KEY,
        user_id INT NOT NULL,
        book_id INT NOT NULL,
        borrow_date DATE NOT NULL,
        return_date DATE,
        FOREIGN KEY(user_id) REFERENCES users(id),
        FOREIGN KEY(book_id) REFERENCES books(id)
    )
    """
    execute_query(connection, create_borrow_table)

    connection.close()
