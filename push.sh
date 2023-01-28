#! /bin/bash

source .env
COMMIT_NUMBER=$(($COMMIT_NUMBER+1))
echo "COMMIT_NUMBER=$COMMIT_NUMBER" > .env
python3 trim.py
git add --a
git commit -m"Backup Commit Number $COMMIT_NUMBER"
cat ../PAT
git push
