"""
Main application to demonstrate CRUD operations for the ERD-based system using SQL Server (T-SQL queries).
Edit the connection string for your MS SQL Server.
"""
import pyodbc

# Connection string for MS SQL Server (edit as needed)
CONN_STR = (
    'DRIVER={ODBC Driver 17 for SQL Server};'
    'SERVER=localhost;'
    'DATABASE=TaskWorker;'
    'Trusted_Connection=yes;'
)

# Simple in-memory log for operations
operation_log = []

def log_operation(operation):
    from datetime import datetime
    operation_log.append(f"[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] {operation}")

# Input validation functions
def get_int_input(prompt, min_value=None, max_value=None):
    while True:
        value = input(prompt)
        try:
            ivalue = int(value)
            if min_value is not None and ivalue < min_value:
                print(f"Value must be >= {min_value}.")
                continue
            if max_value is not None and ivalue > max_value:
                print(f"Value must be <= {max_value}.")
                continue
            return ivalue
        except ValueError:
            print("Please enter a valid integer.")

def get_nonempty_str(prompt, max_length=None):
    while True:
        value = input(prompt).strip()
        if not value:
            print("Input cannot be empty.")
            continue
        if max_length and len(value) > max_length:
            print(f"Input must be at most {max_length} characters.")
            continue
        return value

# CLIENT CRUD operations
def add_client():
    name = get_nonempty_str('Enter client name: ', 50)
    phone = get_nonempty_str('Enter client phone: ', 11)
    address = get_nonempty_str('Enter client address: ', 100)
    payment_info = get_nonempty_str('Enter payment info: ', 100)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('INSERT INTO CLIENT (NAME, PHONE, ADDRESS, PAYMENT_INFO) VALUES (?, ?, ?, ?)',
                        (name, phone, address, payment_info))
        conn.commit()
        print('Client added.')
    log_operation(f"Added client: {name}")

def list_clients():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT CLIENT_ID, NAME, PHONE, ADDRESS FROM CLIENT')
        rows = cursor.fetchall()
        print('Clients:')
        for row in rows:
            print(f'- {row.CLIENT_ID}: {row.NAME}, {row.PHONE}, {row.ADDRESS}')

def print_clients():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM CLIENT')
        rows = cursor.fetchall()
        print('All client records:')
        for row in rows:
            print(row)

def update_client():
    client_id = get_int_input('Enter client ID to update: ', 1)
    new_name = get_nonempty_str('Enter new name: ', 50)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('UPDATE CLIENT SET NAME = ? WHERE CLIENT_ID = ?', (new_name, client_id))
        if cursor.rowcount:
            print(f'Client {client_id} updated.')
            log_operation(f"Updated client ID {client_id} to name: {new_name}")
        else:
            print('Client not found.')
        conn.commit()

def delete_client():
    client_id = get_int_input('Enter client ID to delete: ', 1)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('DELETE FROM CLIENT WHERE CLIENT_ID = ?', (client_id,))
        if cursor.rowcount:
            print(f'Client {client_id} deleted.')
            log_operation(f"Deleted client ID {client_id}")
        else:
            print('Client not found.')
        conn.commit()

# WORKER CRUD operations
def add_worker():
    name = get_nonempty_str('Enter worker name: ', 50)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('INSERT INTO WORKER (NAME) VALUES (?)', (name,))
        conn.commit()
        print('Worker added.')
    log_operation(f"Added worker: {name}")

def list_workers():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT WORKER_ID, NAME FROM WORKER')
        rows = cursor.fetchall()
        print('Workers:')
        for row in rows:
            print(f'- {row.WORKER_ID}: {row.NAME}')

def print_workers():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM WORKER')
        rows = cursor.fetchall()
        print('All worker records:')
        for row in rows:
            print(row)

def update_worker():
    worker_id = get_int_input('Enter worker ID to update: ', 1)
    new_name = get_nonempty_str('Enter new name: ', 50)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('UPDATE WORKER SET NAME = ? WHERE WORKER_ID = ?', (new_name, worker_id))
        if cursor.rowcount:
            print(f'Worker {worker_id} updated.')
            log_operation(f"Updated worker ID {worker_id} to name: {new_name}")
        else:
            print('Worker not found.')
        conn.commit()

def delete_worker():
    worker_id = get_int_input('Enter worker ID to delete: ', 1)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('DELETE FROM WORKER WHERE WORKER_ID = ?', (worker_id,))
        if cursor.rowcount:
            print(f'Worker {worker_id} deleted.')
            log_operation(f"Deleted worker ID {worker_id}")
        else:
            print('Worker not found.')
        conn.commit()

# TASK CRUD operations

def add_task():
    # Show all requests for user to pick from
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT REQUEST_ID, REQUEST_ADDRESS FROM REQUEST')
        requests = cursor.fetchall()
        if not requests:
            print('No requests found. Please add a request first.')
            return
        print('Available requests:')
        for req in requests:
            print(f'- ID: {req.REQUEST_ID}, Address: {req.REQUEST_ADDRESS}')
    task_name = get_nonempty_str('Enter task name: ', 50)
    request_id = get_int_input('Enter request ID: ', 1)
    avg_fee = get_int_input('Enter average fee: ', 0)
    avg_time_finish = input('Enter average finish time (YYYY-MM-DD HH:MM:SS) or leave blank: ').strip()
    # Check if request exists before inserting
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT 1 FROM REQUEST WHERE REQUEST_ID = ?', (request_id,))
        if not cursor.fetchone():
            print(f'Error: Request ID {request_id} does not exist. Task not added.')
            return
        if avg_time_finish:
            cursor.execute('INSERT INTO TASK (TASK_NAME, REQUEST_ID, AVG_FEE, AVG_TIME_FINISH) VALUES (?, ?, ?, ?)',
                            (task_name, request_id, avg_fee, avg_time_finish))
        else:
            cursor.execute('INSERT INTO TASK (TASK_NAME, REQUEST_ID, AVG_FEE) VALUES (?, ?, ?)',
                            (task_name, request_id, avg_fee))
        conn.commit()
        print('Task added.')
    log_operation(f"Added task: {task_name}")

def list_tasks():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT TASK_ID, TASK_NAME, REQUEST_ID, AVG_FEE, AVG_TIME_FINISH FROM TASK')
        rows = cursor.fetchall()
        print('Tasks:')
        for row in rows:
            print(f'- {row.TASK_ID}: {row.TASK_NAME}, Request ID: {row.REQUEST_ID}, Fee: {row.AVG_FEE}, Finish: {row.AVG_TIME_FINISH}')

def print_tasks():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM TASK')
        rows = cursor.fetchall()
        print('All task records:')
        for row in rows:
            print(row)

def update_task():
    task_id = get_int_input('Enter task ID to update: ', 1)
    new_name = get_nonempty_str('Enter new task name: ', 50)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('UPDATE TASK SET TASK_NAME = ? WHERE TASK_ID = ?', (new_name, task_id))
        if cursor.rowcount:
            print(f'Task {task_id} updated.')
            log_operation(f"Updated task ID {task_id} to name: {new_name}")
        else:
            print('Task not found.')
        conn.commit()

def delete_task():
    task_id = get_int_input('Enter task ID to delete: ', 1)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('DELETE FROM TASK WHERE TASK_ID = ?', (task_id,))
        if cursor.rowcount:
            print(f'Task {task_id} deleted.')
            log_operation(f"Deleted task ID {task_id}")
        else:
            print('Task not found.')
        conn.commit()

# REQUEST CRUD operations

def add_request():
    # Show all clients for user to pick from
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT CLIENT_ID, NAME FROM CLIENT')
        clients = cursor.fetchall()
        if not clients:
            print('No clients found. Please add a client first.')
            return
        print('Available clients:')
        for client in clients:
            print(f'- ID: {client.CLIENT_ID}, Name: {client.NAME}')
    client_id = get_int_input('Enter client ID: ', 1)
    request_address = get_nonempty_str('Enter request address: ', 100)
    # Check if client exists before inserting
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT 1 FROM CLIENT WHERE CLIENT_ID = ?', (client_id,))
        if not cursor.fetchone():
            print(f'Error: Client ID {client_id} does not exist. Request not added.')
            return
        cursor.execute('INSERT INTO REQUEST (CLIENT_ID, REQUEST_ADDRESS) VALUES (?, ?)',
                       (client_id, request_address))
        conn.commit()
        print('Request added.')
    log_operation(f"Added request for client ID {client_id}")

def list_requests():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT REQUEST_ID, CLIENT_ID, REQUEST_ADDRESS FROM REQUEST')
        rows = cursor.fetchall()
        print('Requests:')
        for row in rows:
            print(f'- {row.REQUEST_ID}: Client ID: {row.CLIENT_ID}, Address: {row.REQUEST_ADDRESS}')

def print_requests():
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM REQUEST')
        rows = cursor.fetchall()
        print('All request records:')
        for row in rows:
            print(row)

def update_request():
    request_id = get_int_input('Enter request ID to update: ', 1)
    new_address = get_nonempty_str('Enter new request address: ', 100)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('UPDATE REQUEST SET REQUEST_ADDRESS = ? WHERE REQUEST_ID = ?', (new_address, request_id))
        if cursor.rowcount:
            print(f'Request {request_id} updated.')
            log_operation(f"Updated request ID {request_id} to address: {new_address}")
        else:
            print('Request not found.')
        conn.commit()

def delete_request():
    request_id = get_int_input('Enter request ID to delete: ', 1)
    with pyodbc.connect(CONN_STR) as conn:
        cursor = conn.cursor()
        cursor.execute('DELETE FROM REQUEST WHERE REQUEST_ID = ?', (request_id,))
        if cursor.rowcount:
            print(f'Request {request_id} deleted.')
            log_operation(f"Deleted request ID {request_id}")
        else:
            print('Request not found.')
        conn.commit()

def generate_report():
    print('\n--- Operations Report ---')
    if not operation_log:
        print('No operations have been performed yet.')
    else:
        for entry in operation_log:
            print(entry)
    input('Press Enter to return to main menu...')

# Menus
def client_menu():
    while True:
        print('\n--- CLIENT Table Menu ---')
        print('1. Add client')
        print('2. List clients')
        print('3. Update client')
        print('4. Delete client')
        print('5. Print all client records')
        print('0. Back to main menu')
        choice = input('Select an option: ')
        if choice == '1':
            add_client()
        elif choice == '2':
            list_clients()
        elif choice == '3':
            update_client()
        elif choice == '4':
            delete_client()
        elif choice == '5':
            print_clients()
        elif choice == '0':
            break
        else:
            print('Invalid option. Please try again.')

def worker_menu():
    while True:
        print('\n--- WORKER Table Menu ---')
        print('1. Add worker')
        print('2. List workers')
        print('3. Update worker')
        print('4. Delete worker')
        print('5. Print all worker records')
        print('0. Back to main menu')
        choice = input('Select an option: ')
        if choice == '1':
            add_worker()
        elif choice == '2':
            list_workers()
        elif choice == '3':
            update_worker()
        elif choice == '4':
            delete_worker()
        elif choice == '5':
            print_workers()
        elif choice == '0':
            break
        else:
            print('Invalid option. Please try again.')

def task_menu():
    while True:
        print('\n--- TASK Table Menu ---')
        print('1. Add task')
        print('2. List tasks')
        print('3. Update task')
        print('4. Delete task')
        print('5. Print all task records')
        print('0. Back to main menu')
        choice = input('Select an option: ')
        if choice == '1':
            add_task()
        elif choice == '2':
            list_tasks()
        elif choice == '3':
            update_task()
        elif choice == '4':
            delete_task()
        elif choice == '5':
            print_tasks()
        elif choice == '0':
            break
        else:
            print('Invalid option. Please try again.')

def request_menu():
    while True:
        print('\n--- REQUEST Table Menu ---')
        print('1. Add request')
        print('2. List requests')
        print('3. Update request')
        print('4. Delete request')
        print('5. Print all request records')
        print('0. Back to main menu')
        choice = input('Select an option: ')
        if choice == '1':
            add_request()
        elif choice == '2':
            list_requests()
        elif choice == '3':
            update_request()
        elif choice == '4':
            delete_request()
        elif choice == '5':
            print_requests()
        elif choice == '0':
            break
        else:
            print('Invalid option. Please try again.')

# Update main menu
def main_menu():
    while True:
        print('\n=== Main Menu: Select Table to Manage ===')
        print('1. CLIENT')
        print('2. WORKER')
        print('3. TASK')
        print('4. REQUEST')
        print('5. Generate report')
        print('0. Exit')
        choice = input('Select a table: ')
        if choice == '1':
            client_menu()
        elif choice == '2':
            worker_menu()
        elif choice == '3':
            task_menu()
        elif choice == '4':
            request_menu()
        elif choice == '5':
            generate_report()
        elif choice == '0':
            print('Exiting.')
            break
        else:
            print('Invalid option. Please try again.')

if __name__ == '__main__':
    main_menu()