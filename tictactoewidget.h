#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QPushButton>
#include <QWidget>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);
    ~TicTacToeWidget();

    enum class Player {
        Invalid, Player1, Player2, Draw
    };
    Q_ENUM(Player);

    Player currentPlayer() const;
    void setCurrentPlayer(Player p);
    void initNewGame();

signals:
    void currentPlayerChanged(TicTacToeWidget::Player);
    void gameOver(TicTacToeWidget::Player);

private slots:
    void handleButtonClick(int index);

private:
    QVector<QPushButton*> m_board;
    Player m_currentPlayer;

    Player checkWinCondition() const;
    Player checkWinConditionForLine(int index1, int index2, int index3) const;

};

#endif // TICTACTOEWIDGET_H
