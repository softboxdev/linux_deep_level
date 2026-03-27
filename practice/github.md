
## Установка Git


1. Обновите список пакетов:
   ```bash
   sudo apt update
   ```
2. Установите Git:
   ```bash
   sudo apt install git
   ```
3. Проверьте установку, выполнив команду:
   ```bash
   git --version
   ```
   

## Настройка Git

После установки необходимо настроить имя и email, которые будут указываться в коммитах. Выполните команды, заменив `[Your Name]` и `[your_email@example.com]` на свои данные

```bash
git config --global user.name "[Your Name]"
git config --global user.email "[your_email@example.com]"
```

Чтобы проверить текущие настройки, используйте команду:
```bash
git config --list
```

## Установка и настройка SSH-ключей для GitHub

SSH-ключи обеспечивают безопасный способ аутентификации при работе с удалёнными репозиториями.  [```11```](https://www.geeksforgeeks.org/git/push-codes-from-linux-ubuntu-to-github-using-ssh-key/)

1. Сгенерируйте SSH-ключ перейдя в папку ~/.ssh "cd ~/.ssh" . Рекомендуется использовать алгоритм `ed25519`:
   ```bash
   ssh-keygen -t ed25519 -C "your_email@example.com"
   ```
   Где:
   * `-t ed25519`  —  тип алгоритма шифрования;
   * `-C "your_email@example.com"`  —  комментарий (обычно email), который поможет идентифицировать ключ.

   Система предложит указать путь для сохранения ключа. Нажмите `Enter`, чтобы использовать путь по умолчанию (`~/.ssh/id_ed25519`). Также можно задать парольную фразу для дополнительной защиты ключа.  [```11```](https://www.geeksforgeeks.org/git/push-codes-from-linux-ubuntu-to-github-using-ssh-key/)[```7```](https://dev.to/kellycarvalho/how-to-configure-git-on-ubuntu-and-adding-ssh-key-to-github-4h5d)

2. Добавьте приватный ключ в `ssh-agent` (менеджер ключей для SSH):
   ```bash
   eval "$(ssh-agent -s)"
   ssh-add ~/.ssh/id_ed25519
   ```

3. Скопируйте содержимое публичного ключа:
   ```bash
   cat ~/.ssh/id_ed25519.pub
   ```

4. Добавьте публичный ключ в настройки аккаунта GitHub:
   * Перейдите в настройки аккаунта на GitHub: **Settings** → **SSH and GPG keys**.
   * Нажмите **New SSH key**.
   * В поле **Key** вставьте скопированный публичный ключ.
   * Укажите название ключа в поле **Title** и нажмите **Add SSH key**.  [```7```](https://dev.to/kellycarvalho/how-to-configure-git-on-ubuntu-and-adding-ssh-key-to-github-4h5d)[```9```](https://habr.com/ru/articles/755036/)

5. Проверьте подключение:
   ```bash
   ssh -T git@github.com
   ```
   При успешном подключении вы увидите сообщение о успешной аутентификации.  [```11```](https://www.geeksforgeeks.org/git/push-codes-from-linux-ubuntu-to-github-using-ssh-key/)


## Залить код на GitHub

Создайте репозиторий для своего проекта. Скопируйте адрес репозитория по ssh (название должно заканчиваться на .git)

```
git init 

git add .

git commit -m "JIRA_TASK_NUMBER"

git branch -M main

git remote add origin ССЫЛКАНАВАШРЕПОЗИТОРИЙ.git

git push origin main
```

Обычный коммит:

```
git pull origin main

git add .

git commit -m "text"

git push origin ai_service

```

Внимание! Имейте ввиду что вместо main вы указываете ту ветку на которой работаете в репозитории.