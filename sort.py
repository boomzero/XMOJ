import os
import shutil

# Create subdirectories if they don't exist
for i in range(1, 9):
    subdir = f'{i}xxx_files'
    if not os.path.exists(subdir):
        os.makedirs(subdir)

# Move files to the appropriate subdirectory
for filename in os.listdir('.'):
    if os.path.isfile(filename) and filename.endswith('.cpp'):
        first_digit = filename[0]
        if first_digit.isdigit():
            subdir = f'{first_digit}000-{first_digit}999'
            shutil.move(filename, os.path.join(subdir, filename))

