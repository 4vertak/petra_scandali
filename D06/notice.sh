#!/bin/bash
BOT_TOKEN=$TELEGRAM_BOT_TOKEN
USER_ID=$TELEGRAM_USER_ID

if [ -z "$BOT_TOKEN" ] || [ -z "$USER_ID" ]; then
  echo "Ошибка: Необходимо установить TELEGRAM_BOT_TOKEN и TELEGRAM_USER_ID."
  exit 1
fi

URL="https://api.telegram.org/bot$BOT_TOKEN/sendMessage"
TEXT="Deploy status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG%0AStage:+$CI_JOB_STAGE%0AStatus:+$CI_JOB_STATUS"

curl -s -d "chat_id=$USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null