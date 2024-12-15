package com.example.counter;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    TextView ctr;
    Button start, stop;
    int counter=0;
    boolean running=false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        start=(Button)findViewById(R.id.btn_start);
        stop=(Button)findViewById(R.id.btn_stop);
        ctr=(TextView)findViewById(R.id.counter);
        start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                counter=0;
                running=true;
                new MyCounter().start();
            }
        });
        stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                running=false;
            }
        });
    }

    Handler handler=new Handler()
    {
        public void handleMessage(Message m)
        {
            ctr.setText(String.valueOf(m.what));
        }
    };

    class MyCounter extends Thread
    {
        public void run()
        {
            while(running)
            {
                counter++;
                handler.sendEmptyMessage(counter);
                try {
                    Thread.sleep(1000);
                }
                catch (Exception e)
                { }
            }
        }
    }
}

