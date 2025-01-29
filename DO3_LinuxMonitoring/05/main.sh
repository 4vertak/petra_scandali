#!/bin/bash

# ================================================
# 1. ПРОВЕРКА ПАРАМЕТРОВ
# ================================================

if [ "$#" -ne 1 ]; then
    echo "Ошибка: требуется в параметре указать путь до каталога."
    echo "Использование: $0 <путь/>"
    exit 1
fi

DIR="${1%/}/"

if [ ! -d "$DIR" ]; then
    echo "Ошибка: по адресу $DIR, папка не найдена"
    exit 1
fi

# ================================================
# 2. ФОРМИРОВАНИЕ ВЫВОДА
# ================================================

START_TIME=$(date +%s)
TOTAL_FOLDERS=$(find "$DIR" -type d | wc -l)
count_top_folders=1
TOP_FOLDERS=$(du -h --max-depth=1 "$DIR" 2>/dev/null | sort -hr | head -n 6 | while read -r size path; do
    if [ "$path" != "$DIR" ]; then
        echo "$count_top_folders - $path, $size"
        ((count_top_folders++))
    fi
done)
TOTAL_FILES=$(find "$DIR" -type f | wc -l)
CONFIG_FILES=$(find "$DIR" -type f -name "*.conf" | wc -l)
TEXT_FILES=$(find "$DIR" -type f -exec file --mime-type {} + | grep -c "text/plain")
EXECUTABLE_FILES=$(find "$DIR" -type f -executable -exec file {} + | grep -c -E "executable|script")
LOG_FILES=$(find "$DIR" -type f -name "*.log" | wc -l)
ARCHIVE_FILES=$(find "$DIR" -type f -exec file --mime-type {} + | grep -c -E "application/(zip|x-tar|x-gzip|x-bzip2)")
SYMLINKS=$(find "$DIR" -type l -exec file {} + | grep -c "symbolic link to")
count_top_files=1
TOP_FILES=$(find "$DIR" -type f -exec du -h {} + 2>/dev/null | sort -hr | head -n 10 | while read -r size path; do
    type=$(file -b --mime-type "$path")
    echo "$count_top_files - $path, $size, $type"
    ((count_top_files++))
done)
count_top_exec=1
TOP_EXECUTABLES=$(find "$DIR" -type f -executable -exec du -h {} + 2>/dev/null | sort -hr | head -n 10 | while read -r size path; do
    hash=$(md5sum "$path" | awk '{print $1}')
    echo "$count_top_exec - $path, $size, $hash"
    ((count_top_exec++))
done)
END_TIME=$(date +%s)
EXECUTION_TIME=$((END_TIME - START_TIME))

# ================================================
# 3. ВЫВОД ИНФОРМАЦИИ
# ================================================
count_top_folders=1

echo "Total number of folders (including all nested ones) = $TOTAL_FOLDERS"
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
echo "$TOP_FOLDERS"
echo "Total number of files = $TOTAL_FILES"
echo "Number of:"
echo "  Configuration files (with the .conf extension) = $CONFIG_FILES"
echo "  Text files = $TEXT_FILES"
echo "  Executable files = $EXECUTABLE_FILES"
echo "  Log files (with the extension .log) = $LOG_FILES"
echo "  Archive files = $ARCHIVE_FILES"
echo "  Symbolic links = $SYMLINKS"
echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
echo "$TOP_FILES"
echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):"
echo "$TOP_EXECUTABLES"
echo "Script execution time (in seconds) = $EXECUTION_TIME"