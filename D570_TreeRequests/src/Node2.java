public class Node2 {
    private int number;
    private char letter;
    private int preOrder;
    private int postOrder;

    public Node2(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public char getLetter() {
        return letter;
    }

    public void setLetter(char letter) {
        this.letter = letter;
    }

    public int getPreOrder() {
        return preOrder;
    }

    public void setPreOrder(int preOrder) {
        this.preOrder = preOrder;
    }

    public int getPostOrder() {
        return postOrder;
    }

    public void setPostOrder(int postOrder) {
        this.postOrder = postOrder;
    }
}
