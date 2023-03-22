CONTEST_TEMPLATE="Contest_Template/"
QUESTION_TEMPLATE="Contest_Template/Problem/"
function new()
{
    cp -r $CONTEST_TEMPLATE $1
}
function newQuestion()
{
    cp -r $QUESTION_TEMPLATE $1
}


${@:1}
