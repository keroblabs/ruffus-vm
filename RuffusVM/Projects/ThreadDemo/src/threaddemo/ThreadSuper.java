package ThreadDemo;

public class ThreadSuper extends Thread
{
	protected int my_id;
	protected float m_value = ( float )1.0;
	
	public ThreadSuper()
	{
		my_id = (int)getId();
	}
	
	public int GetMyID()
	{
		return my_id;
	}
	
	public float set_float( float value )
	{
		float ret = m_value;
		m_value = value;
		return ret;
	}
	
	@Override
	public void run()
	{
		my_run();
	}

	public void my_run()
	{
	}
}
