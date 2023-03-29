#!/bin/bash

echo 'Привет, ты запустил скрипт, который анализирует файлы лога'
echo 'Введи, пожалуйста, путь для необходимого тебе файла'
read file # сам файл и его путь
if [ -f "$file" ]; then #  проверка пути на существование
    let countLines="$(wc -l ./$file | cut -d'.' -f1)" # количество строк
    let countUnique="$(sort $file | cut -d'-' -f1 | uniq -u | wc -l)" # количество уникальных файлов
    let countChanges="$(sort $file | awk '{print $8}' | uniq -u | wc -l)" # количество изменений, приведших к изменению hash
    if [ "$(sort $file | awk '{print $8}' | wc -l | wc -m)" -gt 4 ]; then # проверка hash на null
        let countChanges=countChanges-1
    fi
    if [ $countLines -gt 0 ] && [ $countUnique -eq 0 ]; then # проверка количества уникальных файлов 
        let countUnique=countUnique+1
    fi
    echo "$countLines $countUnique $countChanges"
else
    echo 'Файл '"$file"' не найден'
fi 
