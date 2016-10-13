import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SillySortingHelpApplet extends Applet implements MouseListener{
    List<Integer> l=new ArrayList(10);
    int point=-1;
    static boolean clicked=false;
    @Override
    public void init(){
        System.out.println("Hey! Sort the numbers using your favourite algorithm.");
        setBackground(Color.decode("#DCBDA0"));
        for(int i=0;i<10;i++){
           l.add(i);
        }
        Collections.shuffle(l);
    }
    @Override
    public void start(){
        System.out.println("Start");
    }
    @Override
    public void paint(Graphics g){
        g.setColor(Color.decode("#FF7069"));
        g.fillRect(80,100,80,80);
        g.fillRect(200,100,80,80);
        g.fillRect(320,100,80,80);
        g.fillRect(440,100,80,80);
        g.fillRect(560,100,80,80);
        g.fillRect(680,100,80,80);
        g.fillRect(800,100,80,80);
        g.fillRect(920,100,80,80);
        g.fillRect(1040,100,80,80);
        g.fillRect(1160,100,80,80);
        g.setColor(Color.decode("#666666"));
        g.fillRect(550,450,240,80);
        addMouseListener(this);
        g.setColor(Color.white);
        g.setFont(new Font(Font.SANS_SERIF,Font.PLAIN,50)); 
        g.drawString(Integer.toString(l.get(0)),105,155);  
        g.drawString(Integer.toString(l.get(1)),225,155);
        g.drawString(Integer.toString(l.get(2)),345,155);
        g.drawString(Integer.toString(l.get(3)),465,155);
        g.drawString(Integer.toString(l.get(4)),585,155);
        g.drawString(Integer.toString(l.get(5)),705,155);
        g.drawString(Integer.toString(l.get(6)),825,155);
        g.drawString(Integer.toString(l.get(7)),945,155);
        g.drawString(Integer.toString(l.get(8)),1065,155);
        g.drawString(Integer.toString(l.get(9)),1185,155);
        g.drawString("Check",600,510); 
    }
    @Override
    public void mouseClicked(MouseEvent me){
           int temp;
        int meX=me.getX();
        int meY=me.getY();
        Graphics g=getGraphics();
       if(meX>80 && meY>100 && meX<160 && meY<180){
           if(clicked==false){
           point=0;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(75,95,90,90);
           System.out.println(point+"  "+l.get(point));
           }
       else{
           temp=l.get(0);
           clicked=false;
           System.out.print(point);
           l.set(0,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(75,95,90,90);
           System.out.println("Swapped "+l.get(0)+" with "+l.get(point));
       }
    }
       if(meX>200 && meY>100 && meX<280 && meY<180){
           if(clicked==false){
           point=1;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(195,95,90,90);
       }
       else{
           temp=l.get(1);
           clicked=false;
           l.set(1,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(195,95,90,90);
           System.out.println("Swapped "+l.get(1)+" with "+l.get(point));
       }
    }
        if(meX>320 && meY>100 && meX<400 && meY<180){
            if(clicked==false){
           point=2;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(315,95,90,90);
       }
       else{
           temp=l.get(2);
           clicked=false;
           l.set(2,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(315,95,90,90);
           System.out.println("Swapped "+l.get(2)+" with "+l.get(point));
       }
        }
        if(meX>440 && meY>100 && meX<520 && meY<180){
            if(clicked==false){
           point=3;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(435,95,90,90);
       }
       else{
           temp=l.get(3);
           clicked=false;
           l.set(3,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(435,95,90,90);
           System.out.println("Swapped "+l.get(3)+" with "+l.get(point));
       }
        }
        if(meX>560 && meY>100 && meX<640 && meY<180){
            if(clicked==false){
           point=4;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(555,95,90,90);
       }
       else{
           temp=l.get(4);
           clicked=false;
           l.set(4,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(555,95,90,90);
           System.out.println("Swapped "+l.get(4)+" with "+l.get(point));
       }
        }
        if(meX>680 && meY>100 && meX<760 && meY<180){
            if(clicked==false){
           point=5;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(675,95,90,90);
       }
       else{
           temp=l.get(5);
           clicked=false;
           l.set(5,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(675,95,90,90);
           System.out.println("Swapped "+l.get(5)+" with "+l.get(point));
       }
        }
       if(meX>800 && meY>100 && meX<880 && meY<180){
           if(clicked==false){
           point=6;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(795,95,90,90);
       }
       else{
           temp=l.get(6);
           clicked=false;
           l.set(6,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(795,95,90,90);
           System.out.println("Swapped "+l.get(6)+" with "+l.get(point));
       }
       }
       if(meX>920 && meY>100 && meX<1000 && meY<180){
           if(clicked==false){
           point=7;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(915,95,90,90);
       }
       else{
           temp=l.get(7);
           clicked=false;
           l.set(7,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(915,95,90,90);
           System.out.println("Swapped "+l.get(7)+" with "+l.get(point));
       }
       }
       if(meX>1040 && meY>100 && meX<1120 && meY<180){
           if(clicked==false){
           point=8;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(1035,95,90,90);
       }
       else{
           temp=l.get(8);
           clicked=false;
           l.set(8,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(1035,95,90,90);
           System.out.println("Swapped "+l.get(8)+" with "+l.get(point));
       }
       }
       if(meX>1160 && meY>100 && meX<1240 && meY<180){
           if(clicked==false)
           point=9;
           clicked=true;
           g.setColor(Color.CYAN);
           g.drawRect(1155,95,90,90);
       }
       else{
           temp=l.get(9);
           clicked=false;
           l.set(9,l.get(point));
           l.set(point,temp);
           g.setColor(Color.decode("#DCBDA0"));
           g.drawRect(1155,95,90,90);
           System.out.println("Swapped "+l.get(9)+" with "+l.get(point));
       }
    }
    @Override
    public void mouseEntered(MouseEvent me){
        
    }
    @Override
    public void mousePressed(MouseEvent me){
        
    }
    @Override
    public void mouseReleased(MouseEvent me){
        
    }
    @Override
    public void mouseExited(MouseEvent me){

    }    
    @Override
    public void stop(){
        System.out.println("Stopped");
    }
    @Override
    public void destroy(){
        System.out.println("Destroyed");
    }
}