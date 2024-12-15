Activity_main.xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    tools:context=".MainActivity">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:layout_marginRight="10dp"
        android:orientation="horizontal">

        <TextView
            android:layout_width="100dp"
            android:layout_height="match_parent"
            android:layout_weight="1"
            android:text="MEDICINE DATABASE"
            android:textAllCaps="false"
            android:textColor="#740D0101"
            android:textSize="20sp" />

    </LinearLayout>
    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:layout_marginRight="10dp"
        android:orientation="horizontal">

        <TextView

            android:layout_width="75dp"
            android:layout_height="48dp"
            android:layout_weight="1"
            android:text="Insert"
            android:textAllCaps="false"
            android:textColor="#740D0101"
            android:textSize="20sp" />

        <Switch
            android:id="@+id/switch1"
            android:layout_width="wrap_content"
            android:layout_height="48dp"
            android:layout_weight="1" />

        <TextView
            android:id="@+id/textView4"
            android:layout_width="wrap_content"
            android:layout_height="48dp"
            android:layout_weight="1"
            android:text="Fetch"
            android:textSize="20sp" />
    </LinearLayout>

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:layout_marginRight="10dp"
        android:orientation="horizontal">

        <TextView
            android:id="@+id/medtext"
            android:layout_width="100dp"
            android:layout_height="wrap_content"
            android:layout_weight="1"
            android:text="Medicine Name"
            android:textAllCaps="false"
            android:textColor="#740D0101"
            android:textSize="24sp" />

        <EditText
            android:id="@+id/medicinename"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_weight="1"
            android:ems="10"
            android:hint="Enter Medicine Name"
            android:textSize="20sp" />
    </LinearLayout>
    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:layout_marginRight="10dp"
        android:orientation="horizontal">
        <TextView
            android:id="@+id/textView3"
            android:layout_width="100dp"
            android:layout_height="wrap_content"
            android:layout_weight="1"
            android:text="Date"
            android:textAllCaps="false"
            android:textColor="#740D0101"
            android:textSize="24sp" />

        <EditText
            android:id="@+id/date"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_weight="1"
            android:ems="10"
            android:inputType="date"
            android:hint="Enter Date DD/MM/YYYY"
            android:textSize="24sp" />
    </LinearLayout>

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:layout_marginRight="10dp"
        android:orientation="horizontal">

        <TextView
            android:layout_width="100dp"
            android:layout_height="wrap_content"
            android:layout_weight="1"
            android:text="Time of the day"
            android:textAllCaps="false"
            android:textColor="#740D0101"
            android:textSize="20sp" />

        <Spinner
            android:id="@+id/spinner"
            android:layout_width="24dp"
            android:layout_height="48dp"
            android:layout_weight="1"
            android:entries="@array/timeoftheday" />
    </LinearLayout>

    <Button
        android:id="@+id/insert"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:text="INSERT" />

    <Button
        android:id="@+id/fetch"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginTop="10dp"
        android:text="FETCH" />

</LinearLayout>

Project Tab->res->values->String.xml (Spinner values)
<resources>
    <string name="app_name">MedicineReminder</string>
    <string-array name="timeoftheday">
        <item> MORNING </item>
        <item> AFTERNOON </item>
        <item> EVENING </item>
        <item> NIGHT </item>
    </string-array>
</resources>

Mainactivity.java
package com.example.medicinereminder;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;
import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {
    EditText medname,meddate;
    Button insert,fetch;
    Spinner day;
    Switch switch1;
    TextView medtxt;
    DatabaseConnection dbconnection;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        medname=(EditText)findViewById(R.id.medicinename);
        meddate=(EditText)findViewById(R.id.date);
        insert=(Button)findViewById(R.id.insert);
        fetch=(Button)findViewById(R.id.fetch);
        day=(Spinner)findViewById(R.id.spinner);
        switch1=(Switch)findViewById(R.id.switch1);
        medtxt=(TextView)findViewById(R.id.medtext);
        dbconnection=new DatabaseConnection(this);

        fetch.setVisibility(View.INVISIBLE);
        switch1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(!b)
                {
                    fetch.setVisibility(View.INVISIBLE);
                    insert.setVisibility(View.VISIBLE);
                    medname.setVisibility(View.VISIBLE);
                    medtxt.setVisibility(View.VISIBLE);
                }
                else{
                    fetch.setVisibility(View.VISIBLE);
                    insert.setVisibility(View.INVISIBLE);
                    medname.setVisibility(View.INVISIBLE);
                    medtxt.setVisibility(View.INVISIBLE);
                }
            }
        });


        insert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String name=medname.getText().toString();
                String date=meddate.getText().toString();
                String time=day.getSelectedItem().toString();
                boolean insert=dbconnection.insertvalues(name,date,time);
                if(insert==true)
                {
                    Toast.makeText(getApplicationContext(), "Data Inserted", Toast.LENGTH_LONG).show();
                    medname.setText(" ");
                    meddate.setText(" ");
                }
                else {
                    Toast.makeText(getApplicationContext(), "Data Not Inserted", Toast.LENGTH_LONG).show();
                }
            }
        });

        fetch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String date=meddate.getText().toString();
                String time=day.getSelectedItem().toString();
                String med="";
                Cursor c=dbconnection.FetchData(date,time);
                if(c.moveToFirst()) {
                    do {
                        med += (String.valueOf(c.getString(c.getColumnIndexOrThrow("MedicineName"))));
                        med += "\n";
                    } while (c.moveToNext());
                    Toast.makeText(getApplicationContext(), med, Toast.LENGTH_LONG).show();
                }
                else
                    Toast.makeText(getApplicationContext(), "No Entries in Database", Toast.LENGTH_SHORT).show();
            }
        });

    }


}

DatabaseConnection.java
package com.example.medicinereminder;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import androidx.annotation.Nullable;

public class DatabaseConnection extends SQLiteOpenHelper {
    public DatabaseConnection(Context context) {
        super(context, "Medicinedb", null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL("create Table MDTable(MedicineName Text,date TEXT,time TEXT)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }

    public boolean insertvalues(String medname,String meddate,String medtime)
    {
        SQLiteDatabase database=this.getWritableDatabase();
        ContentValues contentValues=new ContentValues();
        contentValues.put("MedicineName",medname);
        contentValues.put("date",meddate);
        contentValues.put("time",medtime);
        long res=database.insert("MDTable",null,contentValues);
        if(res==-1)
            return false;
        else
            return true;
    }

    public Cursor FetchData(String date,String time)
    {
        SQLiteDatabase database=this.getReadableDatabase();
        Cursor c=database.rawQuery("Select * from MDTable where date='"+date+"' AND time='"+time+"'",null);
        return c;
    }
}

